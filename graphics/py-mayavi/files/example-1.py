# Author: Gael Varoquaux <gael.varoquaux@normalesup.org>
# Copyright (c) 2009, Enthought, Inc.
# License: BSD Style.

import numpy as np

# Create data with x and y random in the [-2, 2] segment, and z a
# Gaussian function of x and y.
np.random.seed(12345)
x = 4 * (np.random.random(500) - 0.5)
y = 4 * (np.random.random(500) - 0.5)


def f(x, y):
    return np.exp(-(x ** 2 + y ** 2))

z = f(x, y)

from mayavi import mlab
mlab.figure(1, fgcolor=(0, 0, 0), bgcolor=(1, 1, 1))

# Visualize the points
pts = mlab.points3d(x, y, z, z, scale_mode='none', scale_factor=0.2)

# Create and visualize the mesh
mesh = mlab.pipeline.delaunay2d(pts)
surf = mlab.pipeline.surface(mesh)

mlab.view(47, 57, 8.2, (0.1, 0.15, 0.14))
mlab.show()
