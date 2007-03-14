# New ports collection makefile for:	omake
# Date created:		2006-08-06
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	omake
PORTVERSION=	0.9.6.9.1
CATEGORIES=	devel
MASTER_SITES=	http://omake.metaprl.org/downloads/ \
		http://sunner.elcomnet.ru/~stas/
DISTNAME=	omake-0.9.6.9-1

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A flexible build system

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.[0-9]*$//}
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes

FETCH_CMD?=	/usr/bin/fetch -Rr

MAN1=	omake-base.1 omake-doc.1 omake-language.1 omake-options.1 \
	omake-pervasives.1 omake-quickstart.1 omake-root.1 omake-rules.1 \
	omake-shell.1 omake-system.1 omake.1 osh.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000 && exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
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

#
# Readline code is deeply broken on 4
#
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -E -e \
		"s,^(READLINE_ENABLED[[:space:]]*=[[:space:]]*).*,\1false," \
		${WRKSRC}/mk/make_config ${WRKSRC}/mk/defaults
.endif

.include <bsd.port.post.mk>
