# New ports collection makefile for:   quelcom
# Date created:        27 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	quelcom
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.etse.urv.es/~dmanye/quelcom/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of command-line utilities for MP3 and wave files

USE_GCC=	3.3
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CXXFLAGS+=	-I../lib -I${LOCALBASE}/include ${CPPFLAGS} \
		-DHAVE_DECL_GETOPT -fPIC
LDFLAGS=	-L../lib -L${LOCALBASE}/lib -lintl

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Linker error on alpha 4.x"
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Linker error on ia64"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|make |$$(MAKE) |g ; \
		 s|^CXX=|CXX?=|g ; \
		 s|^CXXFLAGS=|CXXFLAGS+=|g ; \
		 s|^LDFLAGS=|LDFLAGS+=|g ; \
		 s|-L./../lib -lqextra|$$(LDFLAGS) -lqextra|g'

do-install:
.for file in qmp3check qmp3cut qmp3info qmp3join qmp3report qwavcut qwavfade \
	qwavheaderdump qwavinfo qwavjoin qwavsilence
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
.for file in libqextra.so libqmp3.so libqwav.so
	${INSTALL_DATA} ${WRKSRC}/lib/${file} ${PREFIX}/lib
.endfor
.for lang in ca es
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/quelcom.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/quelcom.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
