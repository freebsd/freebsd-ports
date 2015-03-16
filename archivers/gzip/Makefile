# Created by: Cyrille Lefevre <cyrille.lefevre@laposte.net>
# $FreeBSD$

PORTNAME=	gzip
PORTVERSION=	1.6
CATEGORIES=	archivers
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Compression utility designed to be a replacement for compress

USES=		cpe charsetfix makeinfo
GNU_CONFIGURE=	yes

INFO=		gzip
CPE_VENDOR=	gnu

DOC_FILES=	AUTHORS COPYING ChangeLog ChangeLog-2007 INSTALL NEWS README \
		THANKS TODO

OPTIONS_DEFINE=	RSYNCABLE DOCS
OPTIONS_DEFAULT=	RSYNCABLE
RSYNCABLE_DESC=	Include --rsyncable patch

RSYNCABLE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gzip-rsyncable.diff

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
