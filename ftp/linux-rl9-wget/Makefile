PORTNAME=	wget
PORTVERSION=	1.21.1
DISTVERSIONSUFFIX=	-7.el9
CATEGORIES=	ftp linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP(S) and FTP (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/s/wget/

LICENSE=	GPLv3+

USES=		cpe linux:rl9
USE_LINUX_RPM=	nolib

CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
