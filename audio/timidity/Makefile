# New ports collection makefile for:    timidity
# Homepage: http://www.clinet.fi/~toivonen/timidity/
# Version required:     0.2i
# Date created:         17 Nov 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1996/11/15 10:52:00 asami Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.cdrom.com/pub/demos/music/samples/ \
		http://www.clinet.fi/~toivonen/timidity/
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz
EXTRACT_ONLY=   ${DISTNAME}.tar.gz
BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

MAINTAINER=     ache@FreeBSD.ORG


INSTALL_TARGET= install.all

do-configure:
	@cd ${WRKSRC} && \
	sed "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	mv gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/lib/timidity/patch && \
	unzip -q -L ${DISTDIR}${TIINS}

MAN1=           timidity.1

.include <bsd.port.mk>
