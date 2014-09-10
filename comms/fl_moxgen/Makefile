# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fl_moxgen
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	flmoxgen
DISTNAME=	Fl_MoxGen-${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Compute the dimensions of a Moxon Rectangle antenna

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

DESKTOP_ENTRIES=	"Fl_MoxGen" "${COMMENT}" "" "${PORTNAME}" \
			"Network;HamRadio;" false

OPTIONS_DEFINE=	PDF
OPTIONS_DEFAULT=	PDF
PDF_DESC=	Enable PDF Writing (requires libharu)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDF}
 LIB_DEPENDS+=	libhpdf.so:${PORTSDIR}/print/libharu
 ALL_TARGET=	fl_moxgen
.else
 ALL_TARGET=	fl_moxgen_no_pdf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%STAGEDIR%%|${STAGEDIR}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
