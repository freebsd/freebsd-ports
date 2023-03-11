PORTNAME=	freac
PORTVERSION=	1.1.7
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free, open-source audio converter and CD ripper
WWW=		https://www.freac.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libboca-1.0.so:audio/boca \
		libsmooth-0.9.so:devel/smooth

USES=		desktop-file-utils gmake
USE_GITHUB=	yes
GH_ACCOUNT=	enzo1982

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,INSTALL_PROGRAM,BSD_&,' \
	    -e '/DLLNAME/s,INSTALL_DATA,BSD_INSTALL_LIB,' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,INSTALL_DATA,BSD_INSTALL_LIB,' \
		${WRKSRC}/Makefile-commands

.include <bsd.port.mk>
