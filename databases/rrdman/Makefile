PORTNAME=	rrdman
PORTVERSION=	1.0.1
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	SF/rrfw/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Apply Holt-Winters prediction parameters to RRD data
WWW=		https://rrfw.sourceforge.net/rrdman/

BUILD_DEPENDS=	rrdtool:databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	YES
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		perl5
PLIST_FILES=	bin/rrd_hwreapply share/man/man1/rrd_hwreapply.1.gz

.include <bsd.port.mk>
