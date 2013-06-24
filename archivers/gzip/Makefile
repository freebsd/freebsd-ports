# Created by: Cyrille Lefevre <cyrille.lefevre@laposte.net>
# $FreeBSD$

PORTNAME=	gzip
PORTVERSION=	1.6
CATEGORIES=	archivers
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Compression utility designed to be a replacement for compress

USES=		charsetfix
GNU_CONFIGURE=	yes

MAN1=	gunzip.1 gzexe.1 gzip.1 zcat.1 zcmp.1 zdiff.1 zforce.1 \
	zgrep.1 zless.1 zmore.1 znew.1
INFO=	gzip

DOC_FILES=	AUTHORS COPYING ChangeLog ChangeLog-2007 INSTALL NEWS README \
		THANKS TODO

OPTIONS_DEFINE=	RSYNCABLE DOCS
OPTIONS_DEFAULT=	RSYNCABLE
RSYNCABLE_DESC=	Include --rsyncable patch

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRSYNCABLE}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-gzip-rsyncable.diff
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
