PORTNAME=	freac
PORTVERSION=	1.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	09444c7f0a9b3204394914ea18f629567868aacf.diff:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free, open-source audio converter and CD ripper

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
	@${REINPLACE_CMD} -e '/operatingSystem/s,Unknown",&;,' \
		${WRKSRC}/components/extension/protocols/systeminfo.cpp

.include <bsd.port.mk>
