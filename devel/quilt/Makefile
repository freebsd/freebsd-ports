# Created by: Dirk Jagdmann <doj@cubic.org>
# $FreeBSD$

PORTNAME=	quilt
PORTVERSION=	0.61
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH

MAINTAINER=	doj@cubic.org
COMMENT=	Collection of bash scripts to ease working with patch files

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gsed:${PORTSDIR}/textproc/gsed \
		gpatch:${PORTSDIR}/devel/patch \
		diffstat:${PORTSDIR}/textproc/diffstat \
		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		formail:${PORTSDIR}/mail/procmail

USES=		desthack gmake perl5

OPTIONS_DEFINE=	RPMBUILD DOCS NLS
OPTIONS_SUB=	yes
RPMBUILD_DESC=	rpmbuild support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed \
		--without-getopt \
		--with-patch=${LOCALBASE}/bin/gpatch

PORTDOCS=	README README.MAIL quilt.pdf

RPMBUILD_BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm4
RPMBUILD_RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm4
RPMBUILD_CONFIGURE_OFF=	--without-rpmbuild

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

.if !exists(${LOCALBASE}/sbin/sendmail)
PLIST_SUB+=	SENDMAIL=""
.else
PLIST_SUB+=	SENDMAIL="@comment "
.endif

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Makefile.in
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|$$(docdir)/$$(PACKAGE)-$$(VERSION)|$$(docdir)/$$(PACKAGE)|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
