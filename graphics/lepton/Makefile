PORTNAME=	lepton
PORTVERSION=	0.2016.07.16
CATEGORIES=	graphics devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tool for manipulating files in LEP image format

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	dropbox
GH_TAGNAME=	a34ee2f4b0a6454eff8ebe334750dd008d57de35

USES=		autoreconf
GNU_CONFIGURE=	yes
TEST_TARGET=	check
CFLAGS+=	-DBSD -DGIT_REVISION='\"${GH_TAGNAME}\"'
.ifndef WITH_DEBUG
CFLAGS+=	-DNDEBUG
.endif
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions --exclude dependencies
PLIST_FILES=	bin/lepton

.if !${MACHINE_CPU:Mssse3}
IGNORE=	requires SSSE3 features in the processor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lepton ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
