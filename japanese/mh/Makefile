# New ports collection makefile for:	mh (Japanese)
# Date created:		28 March 1995
# Whom:			Akito FUJITA <fujita@zoo.ncl.omron.co.jp>
#
# $FreeBSD$
#

PORTNAME=	mh
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://komadori.planet.sci.kobe-u.ac.jp/pub/MH/ \
		ftp://ftp.chem.eng.himeji-tech.ac.jp/pub/net/mh/
MASTER_SITES_SUBDIR=	motoyuki
DISTNAME=	${PORTNAME}-${VERSION}-JP-${JP_VERSION}

MAINTAINER=	motoyuki@freebsd.org
COMMENT=	Rand MH mail handling system + Japanese patches

BUILD_DEPENDS=	jless:${PORTSDIR}/japanese/less
RUN_DEPENDS=	jless:${PORTSDIR}/japanese/less

VERSION=	6.8.4
JP_VERSION=	3.05

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

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
READMES=	00.READ.ME.1ST CHANGES.JP COMMANDS.JP FAQ.JP FEATURES.JP \
		INSTALL.JP OPTIONS.JP READ-ME.JP TODO.JP

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC}/doc-JP; ${INSTALL_DATA} ${READMES} ${DOCDIR})
.endif

.include <bsd.port.mk>
