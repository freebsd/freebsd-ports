# Ports collection makefile for:  dnsutl
# Version required:     	  1.5
# Date created:			  Nov 05, 1998
# Whom:				  Karl Dietz (Karl.Dietz@triplan.com)
#
# $FreeBSD$
#

DISTNAME=	dnsutl-1.5
CATEGORIES=	net
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/dnsutl/ \
		http://www.tip.net.au/~millerp/dnsutl/  \
		http://gd.tuwien.ac.at/softeng/Aegis/dnsutl/ \
		ftp://ftp.agso.gov.au/pub/Aegis/dnsutl/

MAINTAINER=	Karl.Dietz@triplan.com

GNU_CONFIGURE=	yes
ALL_TARGET=	all sure
INSTALL_TARGET=	install-bin

# the manpages do need a patched GNU groff 1.11a (use -I for include path)
#INSTALL_TAGERT+= install-man
#MAN1=		dns-bootp.1 dns-bootparams.1 dns-ethers-import.1 \
#		dns-ethers.1 dns-filter.1 dns-hosts-import.1 \
#		dns-hosts.1 dns-license.1 dns-ng.1 dns-rev.1

.include <bsd.port.mk>
