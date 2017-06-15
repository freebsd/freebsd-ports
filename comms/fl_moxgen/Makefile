# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fl_moxgen
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/flmoxgen
DISTNAME=	Fl_MoxGen-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Compute the dimensions of a Moxon Rectangle antenna

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

DESKTOP_ENTRIES=	"Fl_MoxGen" "${COMMENT}" "" "${PORTNAME}" \
			"Network;HamRadio;" false

OPTIONS_DEFINE=	PDF
OPTIONS_DEFAULT=	PDF
PDF_DESC=	Enable PDF Writing (requires libharu)

PDF_LIB_DEPENDS=	libhpdf.so:print/libharu
PDF_ALL_TARGET=	fl_moxgen
PDF_ALL_TARGET_OFF=	fl_moxgen_no_pdf

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%STAGEDIR%%|${STAGEDIR}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
