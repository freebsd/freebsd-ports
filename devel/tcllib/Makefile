# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.4
CATEGORIES=		devel tcl83 tcl84
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of utility modules for Tcl

BUILD_DEPENDS=	tclsh:${PORTSDIR}/lang/tcl84

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all test
MAKE_ENV+=	LANG=C

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN=	base64.n calculus.n changelog.n cksum.n cmdline.n \
	combinatorics.n comm.n control.n counter.n crc16.n crc32.n \
	csv.n cvs.n des.n docidx.n docidx_api.n docidx_fmt.n \
	doctoc.n doctoc_api.n doctoc_fmt.n doctools.n doctools_api.n \
	doctools_fmt.n exif.n expander.n fileutil.n ftp.n ftpd.n \
	fuzzy.n graph.n html.n htmlparse.n irc.n javascript.n log.n \
	logger.n math.n matrix.n md4.n md5.n mime.n mpexpand.n \
	ncgi.n nntp.n ntp_time.n optimize.n pool.n pop3.n pop3d.n \
	pop3d_dbox.n pop3d_udb.n prioqueue.n profiler.n queue.n \
	record.n report.n sha1.n skiplist.n smtp.n smtpd.n soundex.n \
	stack.n statistics.n stooop.n struct_list.n struct_tree.n \
	sum.n tcllib_dns.n textutil.n uri.n uuencode.n yencode.n

MANCOMPRESSED=	no

.include <bsd.port.mk>
