# Makefile for MPIO device driver
# Created by Sergey Akifyev <asa@gascom.ru>
# $FreeBSD$
#
# $Id: Makefile,v 1.1 2003/06/19 15:36:18 asa Exp $
KMOD=	mpio
SRCS=	urio.c usb_if.h device_if.h bus_if.h opt_usb.h vnode_if.h
CFLAGS=	-DUSB_VENDOR_DIGITALWAY=0x2735 -DUSB_PRODUCT_DIGITALWAY_MPIO=0x0001

.include <bsd.kmod.mk>
