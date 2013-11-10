# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	seqtools
PORTVERSION=	4.22
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.sanger.ac.uk/pub4/resources/software/seqtools/PRODUCTION/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Tools for visualising sequence alignments

LICENSE=        GPLv3

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GCC=	any
USE_GNOME=	gtk20
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -lexecinfo -lcurl
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
