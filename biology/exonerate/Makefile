PORTNAME=	exonerate
DISTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	https://ftp.ebi.ac.uk/pub/software/vertebrategenomics/exonerate/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Generic tool for biological sequence alignment
WWW=		https://www.ebi.ac.uk/about/vertebrate-genomics/software/exonerate

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=		check

.include <bsd.port.mk>
