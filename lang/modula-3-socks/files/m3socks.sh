#! /bin/sh

if [ $# -eq 0 ]; then
    echo "Usage: $0 command [arguments]" >&2
    exit 2
fi

export M3SOCKS=1
export LD_PRELOAD=/usr/local/lib/m3/FreeBSD2/libm3socks.so
exec "$@"
