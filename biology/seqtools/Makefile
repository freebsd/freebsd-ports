# $FreeBSD$

PORTNAME=	seqtools
PORTVERSION=	4.42.1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.sanger.ac.uk/pub4/resources/software/seqtools/PRODUCTION/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools for visualising sequence alignments

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsqlite3.so:databases/sqlite3

USES=		compiler:c++14-lang execinfo libtool pkgconfig
GNU_CONFIGURE=	yes
#USE_GCC=	any
USE_GNOME=	gtk20
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo -lcurl -lsqlite3 -lm
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
