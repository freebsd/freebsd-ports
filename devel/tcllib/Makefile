# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	tclsh:${PORTSDIR}/lang/tcl83
GNU_CONFIGURE=	yes
ALL_TARGET=	test
MAKE_ENV+=	LANG=C

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN= base64.n cksum.n cmdline.n combinatorics.n comm.n control.n \
	counter.n crc32.n csv.n expander.n fileutil.n ftp.n ftpd.n \
	graph.n html.n htmlparse.n javascript.n log.n math.n matrix.n \
	md5.n mime.n ncgi.n nntp.n pop3.n profiler.n report.n queue.n \
	sha1.n smtp.n smtpd.n stack.n stooop.n sum.n textutil.n tree.n \
	uri.n uuencode.n

MANCOMPRESSED=	no

.include <bsd.port.mk>
