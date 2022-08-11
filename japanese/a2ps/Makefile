PORTNAME=	a2ps
PORTVERSION=	1.45
PORTREVISION=	5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/ \
		LOCAL/tota/a2ps
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Text file to postscript converter (with Japanese support)

LICENSE=	A2PSJ
LICENSE_NAME=	License of a2ps-j
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	paperconf:print/libpaper

USES=		perl5 shebangfix
USE_PERL5=	run

SHEBANG_FILES=	${WRKSRC}/a2ps-j
PLIST_FILES=	bin/a2ps-j
EXTRACT_CMD=	${INSTALL_SCRIPT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	a2ps-j
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/a2ps-j

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/a2ps-j ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
