# Created by: patrick
# $FreeBSD$

PORTNAME=	ample
PORTVERSION=	0.5.7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to listen to your own MP3's away from home

NO_STAGE=	yes
GNU_CONFIGURE=	yes

MAN1=		ample.1
MAN5=		ample.conf.5 ample.html.5
PLIST_FILES=	bin/ample
PLIST_DIRSTRY=	var/log var

post-install:
	@${ECHO_CMD} "@exec mkdir -p %D/var/log" >> ${TMPPLIST}

.include <bsd.port.mk>
