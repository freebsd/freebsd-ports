# New ports collection makefile for:	mh (Japanese)
# Version required:	6.8.4
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $Id: Makefile,v 1.11 1998/05/27 12:58:23 itojun Exp $
#

DISTNAME=	mh-6.8.3
PKGNAME=	ja-mh-6.8.4
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/mh/tar/ \
		ftp://ftp.ics.uci.edu/pub/mh/updates/ \
		ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/
DISTFILES=	mh-6.8.3.tar.Z MH.6.8.4.Z \
		mh-6.8.4-JP-3.00.patch.gz

MAINTAINER=	motoyuki@freebsd.org

BUILD_DEPENDS=	jless:${PORTSDIR}/japanese/less
RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

EXTRACT_ONLY=   mh-6.8.3.tar.Z

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

MAN1=	ali.1 anno.1 bbc.1 burst.1 comp.1 dist.1 folder.1 forw.1 inc.1 mark.1 \
	mh-chart.1 mh.1 mhl.1 mhmail.1 mhn.1 mhook.1 mhparam.1 mhpath.1 \
	msgchk.1 msh.1 next.1 packf.1 pick.1 prev.1 prompter.1 rcvstore.1 \
	refile.1 repl.1 rmf.1 rmm.1 scan.1 send.1 show.1 slocal.1 sortm.1 \
	vmh.1 whatnow.1 whom.1
MAN5=	mh-alias.5 mh-format.5 mh-mail.5 mh-profile.5 mh-sequence.5 mh-tailor.5
MAN8=	ap.8 conflict.8 dp.8 fmtdump.8 install-mh.8 popauth.8 post.8

pre-patch:
	@${GZCAT} ${_DISTDIR}/MH.6.8.4.Z | \
		${PATCH} -d ${WRKSRC} --forward --quiet -p0
	@${GZCAT} ${_DISTDIR}/mh-6.8.4-JP-3.00.patch.gz | \
		${PATCH} -d ${WRKSRC} --forward --quiet -p1

pre-configure:
	@chmod +x ${WRKSRC}/configure

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
