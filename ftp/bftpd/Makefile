# Created by: will
# $FreeBSD$

PORTNAME=	bftpd
PORTVERSION=	4.0
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Very configurable FTP server that can do chroot easily

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--enable-pam

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample
MAN8=		bftpd.8
PORTDOCS=	en pl sk

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
BROKEN=		does not compile on and 8.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bftpd.conf,${PREFIX}/etc/bftpd.conf,' \
		${WRKSRC}/mypaths.h
	@${REINPLACE_CMD} -e 's, -ldl,,g' ${WRKSRC}/configure.in
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MAN8PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${PREFIX}/etc/bftpd.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
