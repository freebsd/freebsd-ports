# New ports collection makefile for:    timidity
# Homepage: http://www.cgs.fi/~tt/timidity/
# Version required:     0.2i
# Date created:         17 Nov 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.6 1998/02/02 11:47:35 jseger Exp $
#

DISTNAME=       timidity-0.2i
CATEGORIES=     audio
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/misc/hardware/soundcard/gus/ \
		http://www.cgs.fi/~tt/timidity/
TIINS=          dgguspat.zip
DISTFILES=      ${TIINS} ${DISTNAME}.tar.gz

MAINTAINER=     ache@FreeBSD.ORG

NO_CDROM=       "Uses copyrighted patches"

BUILD_DEPENDS=  unzip:${PORTSDIR}/archivers/unzip

EXTRACT_ONLY=   ${DISTNAME}.tar.gz
INSTALL_TARGET= install.all
MAN1=           timidity.1

do-configure:
	@cd ${WRKSRC} && \
	sed "s=%PREFIX%=${PREFIX}=" < gravis.cfg > gravis.cfg.new && \
	mv gravis.cfg.new gravis.cfg

post-install:
	cd ${PREFIX}/lib/timidity/patch && \
	unzip -o -q -L ${DISTDIR}/${TIINS}

.include <bsd.port.mk>
