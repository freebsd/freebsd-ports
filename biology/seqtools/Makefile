# $FreeBSD$

PORTNAME=	seqtools
PORTVERSION=	4.30
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.sanger.ac.uk/pub4/resources/software/seqtools/PRODUCTION/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools for visualising sequence alignments

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USES=		execinfo pkgconfig
GNU_CONFIGURE=	yes
USE_GCC=	any
USE_GNOME=	gtk20
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lexecinfo -lcurl -lsqlite3 -lm
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
