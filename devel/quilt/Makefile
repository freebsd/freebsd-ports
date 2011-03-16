# New ports collection makefile for: quilt
# Date created:        20 Oct 2006
# Whom:                Dirk Jagdmann <doj@cubic.org>
#
# $FreeBSD$
#

PORTNAME=	quilt
PORTVERSION=	0.48
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	quilt

MAINTAINER=	doj@cubic.org
COMMENT=	A collection of bash3 scripts to ease working with patch files
DEPRECATED=	Depends on expired shells/bash3
EXPIRATION_DATE=2011-05-01

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash3 \
		gcp:${PORTSDIR}/sysutils/coreutils \
		gsed:${PORTSDIR}/textproc/gsed \
		gpatch:${PORTSDIR}/devel/patch \
		diffstat:${PORTSDIR}/textproc/diffstat \
		gawk:${PORTSDIR}/lang/gawk \
		formail:${PORTSDIR}/mail/procmail
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_PERL5=	yes

OPTIONS=	RPMBUILD "rpmbuild support" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sed=${LOCALBASE}/bin/gsed \
		--without-getopt \
		--with-patch=${LOCALBASE}/bin/gpatch

MAN1=		guards.1 quilt.1
PORTDOCS=	README README.MAIL quilt.pdf

.include <bsd.port.pre.mk>

.if defined(WITH_RPMBUILD)
BUILD_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm
RUN_DEPENDS+=	rpm:${PORTSDIR}/archivers/rpm
PLIST_SUB+=	RPMBUILD=""
.else
CONFIGURE_ARGS+=--without-rpmbuild
PLIST_SUB+=	RPMBUILD="@comment "
.endif

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if !exists(${LOCALBASE}/sbin/sendmail)
PLIST_SUB+=	SENDMAIL=""
.else
PLIST_SUB+=	SENDMAIL="@comment "
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-Makefile.in
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|$$(docdir)/$$(PACKAGE)-$$(VERSION)|$$(docdir)/$$(PACKAGE)|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
