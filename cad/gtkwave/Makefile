# ex:ts=8
# Ports collection makefile for:	gtkwave
# Date created:			May 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkwave
PORTVERSION=	2.0.0.p5
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/gtkwave

DOCS=		doc/*.html doc/*.png doc/*.ps
EXAMPLES=	examples/*.gz examples/*.vcd

post-patch:
	@${GREP} -lR "heapsort" ${WRKSRC}/src | ${XARGS} \
		${REINPLACE_CMD} -e "s/heapsort/hsort/g"

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
