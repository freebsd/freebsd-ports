# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsd
PORTVERSION=	1.0.18
CATEGORIES=	devel
MASTER_SITES=	http://arthurdejong.org/cvsd/ \
		http://wiftp.com/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	CVS pserver daemon

EXTRA_PATCHES=	${FILESDIR}/extra-cvsd-buildroot.in

USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libwrap
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN5=		cvsd.conf.5
MAN8=		cvsd.8 cvsd-buginfo.8 cvsd-buildroot.8 cvsd-passwd.8
PORTDOCS=	FAQ NEWS README
PLIST_FILES=	etc/cvsd/cvsd.conf.sample sbin/cvsd sbin/cvsd-buginfo \
		sbin/cvsd-buildroot sbin/cvsd-passwd
PLIST_DIRSTRY=	etc/cvsd
USE_RC_SUBR=	cvsd

OPTIONS_DEFINE=	DOCS
NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000000
BUILD_DEPENDS=	cvs:${PORTSDIR}/devel/cvs
RUN_DEPENDS=	cvs:${PORTSDIR}/devel/cvs
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsd ${PREFIX}/sbin/cvsd
.for f in cvsd-buginfo cvsd-buildroot cvsd-passwd
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/sbin
.endfor
	@${MKDIR} ${PREFIX}/etc/cvsd
	${INSTALL_DATA} ${WRKSRC}/cvsd.conf-dist ${PREFIX}/etc/cvsd/cvsd.conf.sample
.for FILE in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN5PREFIX}/man/man5
.endfor
.for FILE in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN8PREFIX}/man/man8
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
