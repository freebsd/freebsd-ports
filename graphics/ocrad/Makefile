# New ports collection makefile for:	graphics/ocrad
# Date created:				12.11.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	ocrad
PORTVERSION=	0.14
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	q@galgenberg.net
COMMENT=	OCR program implemented as filter

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		CXX="${CXX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
USE_GCC=	3.4
post-patch:
. for f in main.cc rational.cc
	@${REINPLACE_CMD} 's/std::snprintf/snprintf/g' ${WRKSRC}/$f
. endfor
.endif

.if ${OSVERSION} < 500041
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS} -DHAVE_DECL_GETOPT"
.endif

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PLIST_FILES=	bin/ocrad
.if !defined(NOPORTDOCS)
INFO=		ocrad
MAN1=		ocrad.1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ocrad ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/doc/ocrad.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/doc/ocrad.info ${PREFIX}/info
.endif

.include <bsd.port.post.mk>
