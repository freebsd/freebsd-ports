# New ports collection makefile for:	mh (Japanese)
# Version required:	6.8.3-JP.2c
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $Id: Makefile,v 1.5 1996/11/11 10:12:24 max Exp $
#

DISTNAME=	mh-6.8.3
PKGNAME=	jp-mh-6.8.3
MASTER_SITES=	ftp://omrongw.wg.omron.co.jp/pub/net/mail/
CATEGORIES=	japanese mail
DISTFILES=	mh-6.8.3-JP.2c.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

MAN1=		ali.1 anno.1 burst.1 comp.1 dist.1 folder.1 forw.1 inc.1 \
		mark.1 mh-chart.1 mh.1 mhl.1 mhook.1 mhmail.1 mhn.1 \
		mhparam.1 mhpath.1 msgchk.1 msh.1 next.1 packf.1 pick.1 \
		prev.1 prompter.1 rcvstore.1 refile.1 repl.1 rmf.1 rmm.1 \
		scan.1 send.1 show.1 slocal.1 sortm.1 vmh.1 whatnow.1 whom.1
MAN5=		mh-alias.5 mh-format.5 mh-mail.5 mh-profile.5 mh-sequence.5 \
		mh-tailor.5
MAN8=		ap.8 conflict.8 dp.8 install-mh.8 post.8 fmtdump.8

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
