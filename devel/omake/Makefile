# New ports collection makefile for:	omake
# Date created:		2006-08-06
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	omake
PORTVERSION=	0.9.8.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://omake.metaprl.org/downloads/
DISTNAME=	omake-0.9.8.5-3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible build system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes
MAKE_JOBS_UNSAFE=	yes

FETCH_CMD?=	/usr/bin/fetch -Rr

.if !defined(NOPORTDOCS)
INFO=		omake-doc
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.6)
LIB_DEPENDS+=	readline.6:${PORTSDIR}/devel/readline
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
#
# Dirty hack for PREFIX safety
#
	@${REINPLACE_CMD} -E -e "s,(getenv[[:space:]]+)LIBDIR,\1PREFLIBDIR," \
		${WRKSRC}/mk/defaults

#
# Permissions safety
#
	@${REINPLACE_CMD} -E -e "s,cp -f -m 444,\$$(BSD_INSTALL_DATA)," \
		-e "s,cp -f -m 555,\$$(BSD_INSTALL_PROGRAM)," \
		${WRKSRC}/OMakefile ${WRKSRC}/src/main/OMakefile \
		${WRKSRC}/doc/OMakefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@(cd ${WRKSRC}/doc/html/ && ${COPYTREE_SHARE} \* "${DOCSDIR}/")
	@(cd ${WRKSRC}/doc/info/ \
		&& ${COPYTREE_SHARE} \* "${PREFIX}/${INFO_PATH}/")
.endif

.include <bsd.port.post.mk>
