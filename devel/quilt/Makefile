# Created by: Dirk Jagdmann <doj@cubic.org>
# $FreeBSD$

PORTNAME=	quilt
PORTVERSION=	0.65
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of bash scripts to ease working with patch files

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		gcp:sysutils/coreutils \
		gsed:textproc/gsed \
		gpatch:devel/patch \
		diffstat:textproc/diffstat \
		gawk:lang/gawk
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		formail:mail/procmail

USES=		desthack gmake perl5
NO_ARCH=	yes

OPTIONS_DEFINE=	RPMBUILD DOCS NLS
OPTIONS_SUB=	yes
RPMBUILD_DESC=	rpmbuild support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed \
		--without-getopt \
		--with-patch=${LOCALBASE}/bin/gpatch

PORTDOCS=	README README.MAIL quilt.pdf

RPMBUILD_BUILD_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_RUN_DEPENDS=	rpm:archivers/rpm4
RPMBUILD_CONFIGURE_OFF=	--without-rpmbuild

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

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
