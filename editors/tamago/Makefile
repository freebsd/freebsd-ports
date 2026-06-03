PORTNAME=	tamago
PORTVERSION=	4.0.6.0.20041122.19.15
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	editors elisp

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Egg V4, Multilingual Input Method for Emacsen
WWW=		https://github.com/hrs-allbsd/tamago

LICENSE=	GPLv2

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir="${LOCALBASE}/${EMACS_SITE_LISPDIR}"
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"

# Sometimes parallel build fails with such error as following:
# egg-com.el:35:11: Error: Loading file /wrkdirs/usr/ports/editors/tamago/work-devel_nox/tamago-4.0.6.0.20041122.19.15/egg-edep.elc failed to provide feature `egg-edep'
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	tamago-emacs_*

NO_ARCH=	yes

PLIST_SUB=	ELISPDIR="${EMACS_SITE_LISPDIR}"
PORTDOCS=	AUTHORS ChangeLog ChangeLog.1997-1998 \
		ChangeLog.2000-2001 ChangeLog.2002-2004 \
		PROBLEMS README README.ja.txt TODO egg-anthy.readme
OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ENABLE=	doc

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/egg \
		-name "*.elc" -delete

.include <bsd.port.mk>
