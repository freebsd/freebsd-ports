# New ports collection makefile for:	kwebget
# Date created:				21 September 2001
# Whom:					David <ddavid_3@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	kwebget
PORTVERSION=	0.7
CATEGORIES=	ftp kde
MASTER_SITES=	http://www.kpage.de/download/
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure ${WRKSRC}/kwebget/Makefile.in

.include <bsd.port.mk>
