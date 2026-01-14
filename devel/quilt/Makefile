PORTNAME=	quilt
DISTVERSION=	0.69
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Collection of bash scripts to ease working with patch files
WWW=		https://savannah.nongnu.org/projects/quilt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

_BR_DEPENDS=	bash:shells/bash \
		diffstat:textproc/diffstat \
		gawk:lang/gawk \
		gcp:sysutils/coreutils \
		gdiff:textproc/diffutils \
		ggrep:textproc/gnugrep \
		gpatch:devel/patch \
		gsed:textproc/gsed
BUILD_DEPENDS=	${_BR_DEPENDS}
RUN_DEPENDS=	${_BR_DEPENDS} \
		formail:mail/procmail

USES=		desthack gmake perl5 shebangfix
SHEBANG_FILES=	contrib/spec-filters/obs
SHEBANG_LANG=	sh
sh_OLD_CMD=	/usr/bin/sh
sh_CMD=		${SH}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed \
		--without-getopt \
		--with-patch=${LOCALBASE}/bin/gpatch \
		--with-diff=${LOCALBASE}/bin/gdiff \
		--with-grep=${LOCALBASE}/bin/ggrep

NO_ARCH=	yes

PORTDOCS=	README README.MAIL quilt.pdf

OPTIONS_DEFINE=	DOCS NLS RPMBUILD
OPTIONS_SUB=	yes
RPMBUILD_DESC=	rpmbuild support

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

NLS_USES=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

RPMBUILD_BUILD_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_RUN_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_CONFIGURE_WITH=rpmbuild

.if !exists(${LOCALBASE}/sbin/sendmail)
PLIST_SUB+=	SENDMAIL=""
.else
PLIST_SUB+=	SENDMAIL="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|$$(docdir)/$$(PACKAGE)-$$(VERSION)|$$(docdir)/$$(PACKAGE)|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
