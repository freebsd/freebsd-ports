# Ports collection makefile for:  pear-File_Archive
# Date created:			  18 April 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	File_Archive
PORTVERSION=	1.5.0
CATEGORIES=	archivers www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR class to manipulate tar, gz, tgz, bz2, tbz, zip, ar (deb) files

BUILD_DEPENDS=	${PEARDIR}/MIME/Type.php:${PORTSDIR}/mail/pear-MIME_Type
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_MAIL "PEAR::Mail support" off \
		PEAR_MAIL_MIME "PEAR::Mail_Mime support" off \
		PEAR_CACHE_LITE "PEAR::Cache_Lite support" off

CATEGORY=	File
FILES=		Archive.php Archive/Predicate.php Archive/Reader.php \
		Archive/Writer.php Archive/Predicate/And.php \
		Archive/Predicate/Current.php Archive/Predicate/Custom.php \
		Archive/Predicate/Duplicate.php Archive/Predicate/Ereg.php \
		Archive/Predicate/Eregi.php Archive/Predicate/Extension.php \
		Archive/Predicate/False.php Archive/Predicate/Index.php \
		Archive/Predicate/MaxDepth.php Archive/Predicate/MIME.php \
		Archive/Predicate/MinSize.php Archive/Predicate/MinTime.php \
		Archive/Predicate/Not.php Archive/Predicate/Or.php \
		Archive/Predicate/True.php Archive/Reader/Ar.php \
		Archive/Reader/Archive.php Archive/Reader/Bzip2.php \
		Archive/Reader/ChangeName.php Archive/Reader/Concat.php \
		Archive/Reader/Directory.php Archive/Reader/File.php \
		Archive/Reader/Filter.php Archive/Reader/Gzip.php \
		Archive/Reader/Memory.php Archive/Reader/MimeList.php \
		Archive/Reader/Multi.php Archive/Reader/Relay.php \
		Archive/Reader/Select.php Archive/Reader/Tar.php \
		Archive/Reader/Uncompress.php Archive/Reader/Zip.php \
		Archive/Writer/AddBaseName.php Archive/Writer/Ar.php \
		Archive/Writer/Archive.php Archive/Writer/Bzip2.php \
		Archive/Writer/Files.php Archive/Writer/Gzip.php \
		Archive/Writer/Mail.php Archive/Writer/Memory.php \
		Archive/Writer/MemoryArchive.php Archive/Writer/Multi.php \
		Archive/Writer/Output.php Archive/Writer/Tar.php \
		Archive/Writer/UniqueAppender.php Archive/Writer/Zip.php
DOCS=		readme.txt
TESTS=		test.php
_DOCSDIR=	doc

post-extract:
	@${MV} ${WRKSRC}/File/* ${WRKSRC}

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_MAIL)
RUN_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if defined(WITH_PEAR_MAIL_MIME)
RUN_DEPENDS+=	${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
.endif

.if defined(WITH_PEAR_CACHE_LITE)
RUN_DEPENDS+=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
