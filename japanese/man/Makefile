# New ports collection makefile for:	jman - japanese man with EUC
# Version required:	1.0
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/12/07 13:24:00 asami Exp $
#

DISTNAME=	jp-man-1.0
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/in.coming/PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

RUN_DEPENDS=	${PREFIX}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

post-install:
	@${INSTALL_DATA} /usr/share/tmac/tmac.an ${PREFIX}/share/groff/tmac
	@${INSTALL_DATA} /usr/share/tmac/tmac.groff_an ${PREFIX}/share/groff/tmac

.include <bsd.port.mk>
