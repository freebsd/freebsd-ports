# New ports collection makefile for:	cbb
# Version required:     	0.73
# Date created:			14 September, 1997
# Whom:				kline
#
# $Id: Makefile,v 1.1 1997/09/03 22:56:51 kline Exp kline $
#

DISTNAME=	cbb-0.73
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.me.umn.edu/pub/finance/ \
		ftp://ftp.fifi.org/pub/cbb/

MAINTAINER=	kline@thought.org

RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11/tk42
LIB_DEPENDS=    tk42\\.1\\.:${PORTSDIR}/x11/tk42

NO_BUILD=       yes
USE_PERL5=	yes

pre-configure:
	@${MV} ${WRKSRC}/install.pl ${WRKSRC}/install.pl.in
	@${SED} -e "s:/usr/local:${PREFIX}:"  -e "s:lib/cbb:share/cbb:" \
		${WRKSRC}/install.pl.in > ${WRKSRC}/install.pl

.include <bsd.port.mk>
