# New ports collection makefile for:	Canna
# Version required:	3.2p2
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.7 1995/06/26 09:27:45 asami Exp $
#

DISTNAME=	Canna32p2
PKGNAME=	Canna-3.2.2
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/Canna32/ \
		ftp://ftp.cdrom.com/pub/japanese/titech/Canna32/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_STRIP=	-p1
ALL_TARGET=	canna

pre-configure:
	@(cd ${WRKSRC}; xmkmf)

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib
	@if [ ! -f ${PREFIX}/etc/rc.d/canna.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/canna.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/canna.sh; \
		echo "canna=/usr/local/canna/bin/cannaserver" >> ${PREFIX}/etc/rc.d/canna.sh ;\
		echo "if [ -f $$canna ]; then" >> ${PREFIX}/etc/rc.d/canna.sh ;\
		echo "    rm -f /var/spool/canna/lock/.CANNALOCK*" >> ${PREFIX}/etc/rc.d/canna.sh ;\
		echo "    echo -n ' Canna'; $$canna" >> ${PREFIX}/etc/rc.d/canna.sh ;\
		echo "fi" >> ${PREFIX}/etc/rc.d/canna.sh ;\
		chmod 755 ${PREFIX}/etc/rc.d/canna.sh ;\
	fi

.include <bsd.port.mk>
