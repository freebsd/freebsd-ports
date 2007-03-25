# New ports collection makefile for:	bftpd
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bftpd
PORTVERSION=	1.6
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Very configurable FTP server that can do chroot easily

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-pam

PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample
MAN8=		bftpd.8
PORTDOCS=	en pl

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bftpd.conf,${PREFIX}/etc/bftpd.conf,' \
		${WRKSRC}/mypaths.h
	@${REINPLACE_CMD} -e "s@-ldl@@" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MAN8PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/bftpd.conf ${PREFIX}/etc/bftpd.conf.sample
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}/
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}/
.endif

.include <bsd.port.mk>
