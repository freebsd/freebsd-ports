# New ports collection makefile for:  		privman
# Date created:        				14.06.2003
# Whom:               				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	privman
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.isso.sparta.com/opensource/privman/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library that makes it easy for programs to use privilege separation

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(PACKAGE).d|$$(PACKAGE)|g' \
		${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -e 's|@PACKAGE@.d|@PACKAGE@|g' \
		${WRKSRC}/src/Makefile.in

MAN3=	priv_bind.3 priv_custom.3 priv_daemon.3 priv_execve.3 \
	priv_fopen.3 priv_fork.3 priv_init.3 priv_invoke_cap_fn.3 \
	priv_invoke_info_fn.3 priv_open.3 priv_pam.3 \
	priv_pam_acct_mgmt.3 priv_pam_authenticate.3  priv_pam_chauthtok.3 \
	priv_pam_close_session.3 priv_pam_end.3 priv_pam_fail_delay.3 \
	priv_pam_get_item.3 priv_pam_getenv.3 priv_pam_open_session.3 \
	priv_pam_putenv.3 priv_pam_set_item.3 priv_pam_setcred.3 \
	priv_pam_start.3 priv_pclose.3 priv_popen.3 priv_register_cap_fn.3 \
	priv_register_info_fn.3 priv_rerunas.3 priv_respawn_as.3 \
	priv_wait4.3

MAN5=	privman_conf.5
MAN7=	privman.7

.include <bsd.port.mk>
