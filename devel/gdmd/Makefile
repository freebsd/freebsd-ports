PORTNAME=	gdmd
DISTVERSION=	0.1.0.20210818
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Wrapper providing DMD-like CLI interface to gdc
WWW=		https://github.com/D-Programming-GDC/gdmd

LICENSE=	GPLv2+

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	dmd-script

USE_GITHUB=	yes
GH_ACCOUNT=	D-Programming-GDC
GH_TAGNAME=	ff2c97a

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/gdmd

post-patch:
	@${REINPLACE_CMD} -e 's|"gdc"|"gdc11"|g' \
		${PATCH_WRKSRC}/dmd-script

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dmd-script ${STAGEDIR}${PREFIX}/bin/gdmd

.include <bsd.port.mk>
