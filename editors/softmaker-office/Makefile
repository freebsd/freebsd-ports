# Ports collection makefile for:SoftMaker Office
# Date created:			2006-12-20
# Whom:				Ion-Mihai "IOnut" Tetcu<itetcu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SoftMaker-Office
PORTVERSION=	2006
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://www.softmaker.net/down/
DISTFILES=	ofb06trial.tgz

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Microsoft Word/Excel OpenDocument and OpenOffice.org editor

RUN_DEPENDS=	${LOCALBASE}/bin/xfs:${X_FONTSERVER_PORT}

USE_XORG=	x11

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/officetrial

OPTIONS=	ALL_DICTS "Install all available dictionaries" on

NO_CDROM=	distribution with other products of any kind forbiden
NO_PACKAGE=	distribution with other products of any kind forbiden

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_ALL_DICTS)
DISTFILES+=	sml06dict.tgz
.endif

post-extract:
	cd ${WRKSRC} && ${FIND} . -type f -execdir ${CHMOD} ${SHAREMODE} \{\} \; && \
		${CHMOD} ${BINMODE} planmaker textmaker

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}
	cd ${WRKSRC} && ${CP} -Rp . ${PREFIX}/${PORTNAME}
	${LN} -s ${PREFIX}/${PORTNAME}/planmaker ${PREFIX}/bin/planmaker
	${LN} -s ${PREFIX}/${PORTNAME}/textmaker ${PREFIX}/bin/textmaker

.include <bsd.port.post.mk>
