# Created by: Dirk Jagdmann <doj@cubic.org>
# $FreeBSD$

PORTNAME=	quilt
PORTVERSION=	0.65
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of bash scripts to ease working with patch files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gcp:sysutils/coreutils \
		gsed:textproc/gsed \
		gpatch:devel/patch \
		gdiff:textproc/diffutils \
		diffstat:textproc/diffstat \
		gawk:lang/gawk \
		${LOCALBASE}/bin/grep:textproc/gnugrep
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		formail:mail/procmail

USES=		desthack gmake perl5
NO_ARCH=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed \
		--without-getopt \
		--with-patch=${LOCALBASE}/bin/gpatch \
		--with-diff=${LOCALBASE}/bin/gdiff \
		--with-grep=${LOCALBASE}/bin/grep

PORTDOCS=	README README.MAIL quilt.pdf

OPTIONS_DEFINE=	RPMBUILD DOCS NLS
OPTIONS_SUB=	yes
RPMBUILD_DESC=	rpmbuild support

RPMBUILD_BUILD_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_RUN_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_CONFIGURE_WITH=rpmbuild

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-Makefile.in

.include <bsd.port.options.mk>

.if !exists(${LOCALBASE}/sbin/sendmail)
PLIST_SUB+=	SENDMAIL=""
.else
PLIST_SUB+=	SENDMAIL="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|$$(docdir)/$$(PACKAGE)-$$(VERSION)|$$(docdir)/$$(PACKAGE)|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
