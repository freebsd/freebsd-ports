# New ports collection makefile for:	mp3gain
# Date created:		5 September 2002
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mp3gain
PORTVERSION=	1.4.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A tool to normalize the gain of MP3 files

PLIST_FILES=	bin/mp3gain
USE_ZIP=	yes

NO_WRKSUBDIR=	yes

MAKE_ENV=	PREFIX="${PREFIX}"

pre-patch:
	@${FIND} ${WRKDIR} -type f -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
	@${CP} ${FILESDIR}/Makefile.main ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/mpglibDBL/Makefile

.include <bsd.port.mk>
