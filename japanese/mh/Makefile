# New ports collection makefile for:	mh (Japanese)
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $FreeBSD$
#

PORTNAME=	mh
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	${MASTER_SITE_PORTS_JP} \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/MH/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/
DISTNAME=	${PORTNAME}-${VERSION}-JP-${JP_VERSION}

MAINTAINER=	motoyuki@freebsd.org

BUILD_DEPENDS=	jless:${PORTSDIR}/japanese/less
RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

VERSION=	6.8.4
JP_VERSION=	3.03

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-batchmode \
		--enable-apop=${PREFIX}/etc/pop.auth --enable-rpop

MAN1=	ali.1 anno.1 bbc.1 burst.1 comp.1 dist.1 folder.1 forw.1 inc.1 mark.1 \
	mh-chart.1 mh.1 mhl.1 mhmail.1 mhn.1 mhook.1 mhparam.1 mhpath.1 \
	msgchk.1 msh.1 next.1 packf.1 pgped.1 pick.1 prev.1 prompter.1 rcvstore.1 \
	refile.1 repl.1 rmf.1 rmm.1 scan.1 send.1 show.1 slocal.1 sortm.1 \
	vmh.1 whatnow.1 whom.1
MAN5=	mh-alias.5 mh-format.5 mh-mail.5 mh-profile.5 mh-sequence.5 mh-tailor.5
MAN8=	ap.8 conflict.8 dp.8 fmtdump.8 install-mh.8 post.8
MANLANG=	"" ja
MANCOMPRESSED=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
