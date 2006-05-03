# ex:ts=8
# Ports collection makefile for:	gtkwave
# Date created:			May 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gtkwave
PORTVERSION=	2.0.0.p5
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cs.man.ac.uk/pub/amulet/gtkwave/2.0/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	watchman@ludd.ltu.se
COMMENT=	Electronic Waveform Viewer

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	${PREFIX}/lib/gtkwave

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000 )
USE_GCC=	3.4
.endif

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

.include <bsd.port.post.mk>
