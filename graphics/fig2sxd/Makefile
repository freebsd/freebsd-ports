PORTNAME=	fig2sxd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.1-3
DISTVERSIONSUFFIX=	-gedae2ef
CATEGORIES=	graphics converters

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert .xfig files to the OpenOffice draw format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler gmake
USE_GITLAB=	yes

GL_ACCOUNT=	acfbuerger
GL_COMMIT=	edae2efd428623ac22aec06bdec572fc45c368f3

PLIST_FILES=	bin/fig2sxd man/man1/fig2sxd.1.gz

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CXX/d; s|^\(all:\).*|\1 $$(TARGET1) fig2sxd.1|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
