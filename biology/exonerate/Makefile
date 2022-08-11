PORTNAME=	exonerate
PORTVERSION=	2.4.0
CATEGORIES=	biology
MASTER_SITES=	http://ftp.ebi.ac.uk/pub/software/vertebrategenomics/exonerate/

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Generic tool for sequence alignment

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
TEST_TARGET=	check

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
