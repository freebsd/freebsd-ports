PORTNAME=	fig2sxd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gedae2ef
CATEGORIES=	graphics converters

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert .xfig files to the OpenOffice draw format
WWW=		https://gitlab.com/acfbuerger/fig2sxd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler gmake
USE_GITLAB=	yes
GL_ACCOUNT=	acfbuerger
GL_TAGNAME=	77a24df7a2b1bea8a8a7e73690487a9e80a15d48

PLIST_FILES=	bin/fig2sxd \
		share/man/man1/fig2sxd.1.gz

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CXX/d; s|^\(all:\).*|\1 $$(TARGET1) fig2sxd.1|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
