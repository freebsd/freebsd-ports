# ex:ts=8
# Ports collection makefile for:	gtkwave
# Date created:			May 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkwave
PORTVERSION=	2.0.0.p3
PORTEPOCH=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/gtkwave

post-patch:
	@${GREP} -lR "heapsort" ${WRKSRC}/src | ${XARGS} \
		${REINPLACE_CMD} -e "s/heapsort/hsort/g"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc ; ${INSTALL_DATA} *.png *.ps *.html ${DOCSDIR})
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples ; ${INSTALL_DATA} *.gz *.vcd ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
