# New ports collection makefile for: 	tcllib
# Date created:				27 Apr 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=		tcllib
PORTVERSION=		1.3
CATEGORIES=		devel tcl83
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcllib

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A collection of utility modules for Tcl

BUILD_DEPENDS=	tclsh:${PORTSDIR}/lang/tcl84

GNU_CONFIGURE=	yes
ALL_TARGET=	all nroff-doc
MAKE_ENV+=	LANG=C

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MANN= base64.n calculus.n cksum.n cmdline.n combinatorics.n comm.n \
	control.n counter.n crc32.n csv.n dns.n dtformat.n dtformatter.n \
	exif.n expander.n fileutil.n ftp.n ftpd.n graph.n html.n htmlparse.n \
	irc.n javascript.n log.n math.n matrix.n md5.n mime.n mpexpand.n \
	ncgi.n nntp.n pool.n pop3.n pop3d.n pop3d_dbox.n pop3d_udb.n \
	profiler.n queue.n report.n sha1.n smtp.n smtpd.n stack.n \
	stooop.n sum.n textutil.n tree.n uri.n uuencode.n yencode.n

MANCOMPRESSED=	no

test:
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE} test

# The directory is created by install, but not populated. Just
# remove it for now. In future versions, it may get some files
# and we will remove this target.
post-install: test
	@${RMDIR} ${PREFIX}/lib/tcllib${PORTVERSION}/doctools

.include <bsd.port.mk>
