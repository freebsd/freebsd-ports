# Created by: will
# $FreeBSD$

PORTNAME=	bftpd
PORTVERSION=	4.0
CATEGORIES=	ftp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very configurable FTP server that can do chroot easily

LICENSE=	GPLv2

USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--enable-pam

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample \
		man/man8/bftpd.8.gz
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${STAGEDIR}${PREFIX}/etc/bftpd.conf.sample
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
