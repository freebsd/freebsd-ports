# Ports collection Makefile for:	Hesiod
# Date created:				6/11/1998
# Whom:					n@nectar.com
#
# $FreeBSD$
#

PORTNAME=		hesiod
PORTVERSION=		3.1.0
CATEGORIES=		dns
MASTER_SITES=		ftp://athena-dist.mit.edu/pub/ATHENA/hesiod/

MAINTAINER=		stas@FreeBSD.org
COMMENT=		A directory service built on DNS and BIND

MAN3=			hesiod.3 hesiod_end.3 hesiod_free_list.3 	\
			hesiod_free_passwd.3 hesiod_free_postoffice.3 	\
			hesiod_free_servent.3 hesiod_getmailhost.3 	\
			hesiod_getpwnam.3 hesiod_getpwuid.3 		\
			hesiod_getservbyname.3 hesiod_init.3 		\
			hesiod_resolve.3 hesiod_to_bind.3 		\
			hesiod_free_string.3 hesiod_parse_result.3
MAN5=			hesiod.conf.5

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,\$${INSTALL} -m 444,\$${BSD_INSTALL_MAN}," \
		-e "s,\$${INSTALL} -m 644,\$${BSD_INSTALL_DATA}," \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
