PORTNAME=	gpaint
DISTVERSIONPREFIX=	2-
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNU_ALPHA

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small-scale painting program for GNOME
WWW=		https://www.gnu.org/software/gpaint/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20 libglade2

GNU_CONFIGURE=	yes

LIBS+=		-lm

PLIST_FILES=	${DATADIR}/glade/gpaint.glade \
		bin/gpaint-2

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|_RESPONSE_DISCARD|_RESPONSE_NO|g' ${WRKSRC}/src/drawing.c

.include <bsd.port.mk>
