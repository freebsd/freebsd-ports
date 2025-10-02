PORTNAME=	leocad
DISTVERSIONPREFIX=	v
DISTVERSION=	25.09
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CAD program for creating virtual LEGO models
WWW=		https://www.leocad.org/ \
		https://github.com/leozide/leocad/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

RUN_DEPENDS=	ldraw>0:cad/ldraw

USES=		compiler:c++11-lang cpe desktop-file-utils gl qmake qt:5 \
		shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	leozide
USE_GL=		gl
USE_QT=		concurrent core gui network opengl printsupport widgets xml \
		buildtools:build linguisttools:build

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} \
		LDRAW_LIBRARY_PATH=${PREFIX}/share/ldraw \
		MAN_DIR=${PREFIX}/share/man/man1

PORTSCOUT=	limit:^[0-9\.]*$$ # to ignore the 'continuous' tag

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/leocad

.include <bsd.port.mk>
